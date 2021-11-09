f = lambda m,n,z=0,l=[]: z==0 if z in l else sum(f(m,n,(z+d)%m%(n*1j),l+[z]) for d in(1,1j))

m=>n=>(g=(k,l=k)=>l&(b=1n<<k)?!k:g((k+m)%(m*n),l|=b)+g(k-~k%m-k%m,l))(0n)

m => n => (         // m = width; n = height
  g = (             // g is a recursive function taking:
        x, y        //   the current coordinates (x, y) on the torus
      ) =>          //
    g[              // the surrounding object of g is also used for storage
      x += y * m    // turn x into a key for the current coordinates
    ] ?             // if this cell was already visited:
      !x            //   return 1 if we're back to (0, 0), or 0 otherwise
    :               // else:
      g(            //   first recursive call:
        -~x % m,    //     move to the right
        y,          //     leave y unchanged
        g[x] = 1    //     mark the current cell as visited by setting the flag g[x]
      ) +           //   add the result of
      g(            //   a second recursive call:
        x % m,      //     restore x in [0...m-1]
        -~y % n     //     move up
      ) +           //
      --g[x]        //   clear the flag on the current cell
)(0, 0)             // initial call to g with (x, y) = (0, 0)
