import blackLogo from "../../assets/black-pawn.png"
import whiteLogo from "../../assets/white-pawn.png"
import { Cell } from "../Cell"
import { Colors } from "../Colors"
import { Figure, FigureNames } from "./Figure"

export class Pawn extends Figure {

  isFirstStep: boolean = true;

  constructor(color: Colors, cell: Cell) {
    super(color, cell)
    this.logo = color === Colors.BLACK ? blackLogo : whiteLogo
    this.name = FigureNames.PAWN
  }

  canMove(target: Cell): boolean {
    if (!super.canMove(target)) return false;

    const direction = this.cell.figure?.color === Colors.BLACK ? 1 : -1;
    const firstStepDirection = this.cell.figure?.color === Colors.BLACK ? 2 : -2;

    // Логика для первого хода пешки
    if (target.y === this.cell.y + direction) {
      // Проверка на движение на одну клетку вперед
      if (target.x === this.cell.x && this.cell.board.getCell(target.x, target.y).isEmpty()) {
        return true;
      }

      // Проверка на движение на две клетки вперед
      if (this.cell.board.getCell(target.x, this.cell.y + direction).isEmpty()) {
        return true;
      }

      // Проверка на захват фигуры противника
      if (target.x === this.cell.x + 1 || target.x === this.cell.x - 1) {
        return this.cell.isEnemy(target);
      }
    }

    return false;
  }

  clone(): Pawn {
    return new Pawn(this.color, this.cell);
  }

  moveFigure(target: Cell) {
    super.moveFigure(target);
    this.isFirstStep = false;
  }
}
