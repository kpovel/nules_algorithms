function checkTriangle(points) {
    for (const point of points) {
        const pointsCoincidence = points.filter(item => item.x === point.x || item.y === point.y);
        const fewCoincidenceCoordinate = pointsCoincidence.length > 1;
        
        if (fewCoincidenceCoordinate) {
            return ("These three points don't define the triangle");
        }
    }
    return ("These three points define the triangle");
}

const coordinatePoints = [
    {
        x: 1,
        y: 3
    },
    {
        x: 3,
        y: 3
    },
    {
        x: 4,
        y: 3
    }
];

console.log(checkTriangle(coordinatePoints));