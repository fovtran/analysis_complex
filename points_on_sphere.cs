Vector3[] GetPointsOnSphere2(int nPoints)
   {
       int divisions = (int)(Mathf.Sqrt(nPoints / 5.0f) + 0.5f);
       var points = new List<Vector3>();
       points.Add(new Vector3(0, -1, 0));

       float angle = Mathf.PI / 2 / divisions;

       for (int iLat = -divisions+1; iLat < divisions; ++iLat) {
           float lat = iLat*angle;

           float circumference = 2 * Mathf.PI * Mathf.Cos(lat);
           int steps = (int) (circumference/angle);

           float baseAngle = lat / 2;

           for (int iLon = 0; iLon < steps; ++iLon) {
               float lon = baseAngle + iLon*2*Mathf.PI/steps;
               points.Add(new Vector3(Mathf.Sin(lon)*Mathf.Cos(lat), Mathf.Sin(lat), Mathf.Cos(lon)*Mathf.Cos(lat)));
           }
       }

       points.Add(new Vector3(0, 1, 0));

       return points.ToArray();
   }
