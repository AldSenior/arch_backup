import logo from '../../assets/black-king.png'
import { Cell } from "../Cell"
import { Colors } from "../Colors"

export enum FigureNames {
  FIGURE = "Фигура",
  KING = "Король",
  KNIGHT = "Конь",
  PAWN = "Пешка",
  QUEEN = "Ферзь",
  ROOK = "Ладья",
  BISHOP = "Слон",
}

export class Figure {
  color: Colors
  logo: typeof logo | null
  cell: Cell
  name: FigureNames
  id: number


  constructor(color: Colors, cell: Cell) {
    this.color = color
    this.cell = cell
    this.cell.figure = this
    this.logo = null
    this.name = FigureNames.FIGURE
    this.id = Math.random()
  }
  
  clone(): Figure {
    return new Figure(this.color, this.cell)
  }
  canMove(target: Cell): boolean {
    if (target.figure?.color === this.color)
      return false
    if (target.figure?.name === FigureNames.KING)
      return false
    return true
  }

  moveFigure(target: Cell) { }
}
