while (f.read((char *)&t, sizeof(t)))
	{
		if (t.get_emp_id() == k)
		{
			flag = 1;
			employee *e;
			e = &t;
			e->calculate_salary();
			t.display_gross();
			cout << "\n\t\t**********************************\n";
		}
	}