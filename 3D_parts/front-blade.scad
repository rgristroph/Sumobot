// Front blade of a sumo-jr dozer

difference() {
   cube([3, 110, 50 ], center=true);
   translate([0,67/2 + 5/2,0]) cube([20,5,12.5], center=true);
   translate([0,-(67/2 + 5/2),0]) cube([20,5,12.5], center=true);
}