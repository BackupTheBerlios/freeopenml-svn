export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/lib:$PWD/drivers
export ML_PLUGINS_PATH=$PWD/drivers


TEST="$(find tests/ -type f -perm +u=x)"
if [ -n "$TEST" ]; then
	echo "all test returns 0 on success !=0 else"
	for I in $TEST; do
		$I
		RETVAL=$?
		if [ $RETVAL -ne 0 ]; then
			printf "\e[1;31m%-60.60s returns $RETVAL\e[0m\n" "$I"
		else
			printf "\e[1;32m%-60.60s returns $RETVAL\e[0m\n" "$I"
		fi;
	done
fi
