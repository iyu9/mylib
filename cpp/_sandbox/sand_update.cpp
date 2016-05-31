
//unity template
int mode = 0;
int is_wait_response = 1;
int is_load_resources = 2;

void update() {
		
	if(mode == is_wait_response) {
		return;
	}

	if(mode == is_load_resources) {
		return;
	}

	if(is_www_finish) {
		if(is_success) {}
		if(is_time_over) {}
		if(is_error) {}
		return;
	}	

	do_control();
}
