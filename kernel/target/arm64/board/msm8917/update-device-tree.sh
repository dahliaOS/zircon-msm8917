dtc -I dts -o j4primelte.dtb -O dtb j4primelte-rev00.dts
dtc -I dts -o j4primelte-rev01.dtb -O dtb j4primelte-rev01.dts
dtc -I dts -o j4primelte-rev02.dtb -O dtb j4primelte-rev02.dts
dtc -I dts -o j4primelte-rev03.dtb -O dtb j4primelte-rev03.dts
dtc -I dts -o j4primelte-rev04.dtb -O dtb j4primelte-rev04.dts
dtc -I dts -o j4primelte-rev06.dtb -O dtb j4primelte-rev06.dts
cat j4primelte-rev01.dtb j4primelte-rev02.dtb j4primelte-rev03.dtb j4primelte-rev04.dtb j4primelte-rev06.dtb >> j4primelte.dtb
rm j4primelte-*.dtb
