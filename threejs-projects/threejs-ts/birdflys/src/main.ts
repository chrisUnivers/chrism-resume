import { initBirdFlys } from './initBirdFlys'
import './style.css'

const canvasElement = document.querySelector<HTMLCanvasElement>('#canvasone')
if (canvasElement) {
  initBirdFlys(canvasElement)
}

