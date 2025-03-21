import {BrowserRouter as Router, Routes, Route} from 'react-router-dom'
import { ToastContainer } from 'react-toastify'
import 'react-toastify/dist/ReactToastify.css'
import PrivateRoute from './components/PrivateRoute'
import Home from './pages/Home'
import Login from './pages/Login'
import Register from './pages/Register'
import NewClub from './pages/NewClub'
import SideBarNav from './components/SideBarNav'


function App() {
  return <>
    <Router>
      <div className='leftright'>
        <SideBarNav />
        <div className="homeright">
          <Routes>
            <Route path='/' element={<Home />} />
            <Route path='/login' element={<Login />} />
            <Route path='/register' element={<Register />} />
            <Route path='/new-club' element={<PrivateRoute />}>
              <Route path='/new-club' element={<NewClub />} />
            </Route>
          </Routes>
        </div>
      </div>
    </Router>
    <ToastContainer />
  </>
}

export default App
