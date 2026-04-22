// BazaarX Backend — Express + MongoDB + Razorpay
const express   = require('express');
const mongoose  = require('mongoose');
const bcrypt    = require('bcryptjs');
const jwt       = require('jsonwebtoken');
const cors      = require('cors');
const Razorpay  = require('razorpay');
const crypto    = require('crypto');

const app = express();
app.use(cors());
app.use(express.json());
app.use(express.static('.'));

const MONGO_URI  = 'mongodb://localhost:27017/bazaarx';
const JWT_SECRET = 'bazaarx_super_secret_2025';
const PORT       = 3000;

// 🔑 Replace with your Razorpay credentials from https://razorpay.com/
const razorpay = new Razorpay({
  key_id:     'YOUR_RAZORPAY_KEY_ID',
  key_secret: 'YOUR_RAZORPAY_KEY_SECRET',
});

mongoose.connect(MONGO_URI)
  .then(() => console.log('✅ MongoDB connected'))
  .catch(err => console.error('❌ DB Error:', err));

// Models
const User = mongoose.model('User', new mongoose.Schema({
  name:     String,
  email:    { type: String, unique: true, lowercase: true },
  password: String,
  createdAt:{ type: Date, default: Date.now }
}));

const Order = mongoose.model('Order', new mongoose.Schema({
  userId:            { type: mongoose.Schema.Types.ObjectId, ref: 'User' },
  items:             Array,
  totalAmount:       Number,
  paymentMethod:     String,
  razorpayOrderId:   String,
  razorpayPaymentId: String,
  status:            { type: String, default: 'pending' },
  createdAt:         { type: Date, default: Date.now }
}));

// Auth middleware
function auth(req, res, next) {
  const token = req.headers.authorization?.split(' ')[1];
  if (!token) return res.status(401).json({ error: 'Token required' });
  try { req.user = jwt.verify(token, JWT_SECRET); next(); }
  catch { res.status(401).json({ error: 'Invalid token' }); }
}

// ── Auth Routes ──
app.post('/api/signup', async (req, res) => {
  try {
    const { name, email, password } = req.body;
    if (!name || !email || !password) return res.status(400).json({ error: 'All fields required' });
    if (password.length < 6) return res.status(400).json({ error: 'Password min 6 chars' });
    if (await User.findOne({ email })) return res.status(400).json({ error: 'Email already registered' });
    const hash = await bcrypt.hash(password, 10);
    const user = await new User({ name, email, password: hash }).save();
    const token = jwt.sign({ id: user._id, name, email }, JWT_SECRET, { expiresIn: '7d' });
    res.status(201).json({ token, user: { name, email } });
  } catch (e) { res.status(500).json({ error: e.message }); }
});

app.post('/api/login', async (req, res) => {
  try {
    const { email, password } = req.body;
    const user = await User.findOne({ email });
    if (!user || !(await bcrypt.compare(password, user.password)))
      return res.status(400).json({ error: 'Invalid email or password' });
    const token = jwt.sign({ id: user._id, name: user.name, email }, JWT_SECRET, { expiresIn: '7d' });
    res.json({ token, user: { name: user.name, email } });
  } catch (e) { res.status(500).json({ error: e.message }); }
});

// ── Razorpay Routes ──
app.post('/api/create-order', auth, async (req, res) => {
  try {
    const { amount, items } = req.body;
    const rzp = await razorpay.orders.create({ amount: amount * 100, currency: 'INR', receipt: 'bx_' + Date.now() });
    await new Order({ userId: req.user.id, items, totalAmount: amount, paymentMethod: 'razorpay', razorpayOrderId: rzp.id }).save();
    res.json({ orderId: rzp.id, amount: rzp.amount, currency: rzp.currency });
  } catch (e) { res.status(500).json({ error: e.message }); }
});

app.post('/api/verify-payment', auth, async (req, res) => {
  try {
    const { razorpay_order_id, razorpay_payment_id, razorpay_signature } = req.body;
    const expected = crypto.createHmac('sha256', 'YOUR_RAZORPAY_KEY_SECRET')
      .update(razorpay_order_id + '|' + razorpay_payment_id).digest('hex');
    if (expected !== razorpay_signature) return res.status(400).json({ error: 'Invalid signature' });
    await Order.findOneAndUpdate({ razorpayOrderId: razorpay_order_id }, { razorpayPaymentId: razorpay_payment_id, status: 'paid' });
    res.json({ success: true });
  } catch (e) { res.status(500).json({ error: e.message }); }
});

app.post('/api/cod-order', auth, async (req, res) => {
  try {
    const { items, amount } = req.body;
    const order = await new Order({ userId: req.user.id, items, totalAmount: amount, paymentMethod: 'COD', status: 'confirmed' }).save();
    res.json({ success: true, orderId: order._id });
  } catch (e) { res.status(500).json({ error: e.message }); }
});

app.get('/api/my-orders', auth, async (req, res) => {
  try { res.json(await Order.find({ userId: req.user.id }).sort({ createdAt: -1 })); }
  catch (e) { res.status(500).json({ error: e.message }); }
});

app.listen(PORT, () => {
  console.log(`🚀 BazaarX → http://localhost:${PORT}`);
});
