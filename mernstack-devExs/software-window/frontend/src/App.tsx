import {BrowserRouter as Router, Routes, Route} from 'react-router-dom';
import PrivateRoute from './components/PrivateRoute';
import NewSoftware from './pages/NewSoftware';

function App() {
  return (
    <>
      <Router>
        <Routes>
          <Route path='/new-software' element={<PrivateRoute />}>
              <Route path='/new-software' element={<NewSoftware />} />
            </Route>
        </Routes>
      </Router>
    </>
  )
}

export default App
