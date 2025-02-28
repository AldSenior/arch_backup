import blackLogo from "../../assets/black-pawn.png";
import whiteLogo from "../../assets/white-pawn.png";
import { Cell } from "../Cell";
import { Colors } from "../Colors";
import { Figure, FigureNames } from "./Figure";

export class Pawn extends Figure {
  isFirstStep: boolean = true;

  constructor(color: Colors, cell: Cell) {
    super(color, cell);
    this.logo = color === Colors.BLACK ? blackLogo : whiteLogo;
    this.name = FigureNames.PAWN;
  }

  canMove(target: Cell): boolean {
    if (!super.canMove(target)) return false; // Проверяем, может ли фигура вообще двигаться

    const direction = this.cell.figure?.color === Colors.BLACK ? 1 : -1; // Определяем направление
    const firstStepDirection = this.cell.figure?.color === Colors.BLACK ? 2 : -2; // Определяем направление для первого шага

    // Проверка обычного шага на одну клетку
    if (target.y === this.cell.y + direction && target.x === this.cell.x) {
      return this.cell.board.getCell(target.x, target.y).isEmpty(); // Доступна ли целевая клетка
    }

    // Проверка первого шага на две клетки
    if (this.isFirstStep &&
        target.y === this.cell.y + firstStepDirection && 
        target.x === this.cell.x) {
      return this.cell.board.getCell(target.x, this.cell.y + direction).isEmpty() && // Проверяем, что клетка впереди пуста
             this.cell.board.getCell(target.x, target.y).isEmpty(); // Проверяем, что целевая клетка пуста
    }

    // Проверка диагонального захвата
    if (target.y === this.cell.y + direction && 
        (target.x === this.cell.x + 1 || target.x === this.cell.x - 1)) {
      return this.cell.isEnemy(target); // Проверяем, что клетка занята фигурой противника
    }

    return false;
  }

  clone(): Pawn {
    return new Pawn(this.color, this.cell);
  }

  moveFigure(target: Cell) {
    super.moveFigure(target);
    this.isFirstStep = false; // Устанавливаем, что первый шаг уже сделан
  }
}
