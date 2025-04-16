import {BrowserRouter as Router, Routes, Route} from 'react-router-dom'
import { ToastContainer } from 'react-toastify'
import Home from './pages/Home'
import Login from './pages/Login'
import Register from './pages/Register'
import NewSoftware from './pages/NewSoftware'
import PrivateRoute from './components/PrivateRoute'
import Header from './components/Header'


function App() {

  return (
    <>
      <Router>
      <div className='container'>
        <Header />
        <Routes>
          <Route path='/' element={<Home />} />
          <Route path='/login' element={<Login />} />
          <Route path='/register' element={<Register />} />
          <Route Route path='/create-software' element={<PrivateRoute />}>
            <Route path='/create-software' element={<NewSoftware />} />
          </Route>
        </Routes>
      </div>
    </Router>
    <ToastContainer />
    </>
  )
}

export default App
