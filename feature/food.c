// food.c

#include <dbase.h>
#include <name.h>

void init()
{
    if(this_player()==environment())
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        if( !living(this_player()))
		return 1;
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( !query("food_remaining") )
		return notify_fail( name() + "�Ѿ�ûʲô�óԵ��ˡ�\n");

	if( (int)this_player()->query("food") >= 
		(int)this_player()->max_food_capacity() ) {
		write("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");
		return 1;
	}
	// mon 6/12/98
        //	return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");

	this_player()->add("food", query("food_supply"));
	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	// This allows customization of drinking effect.
	if( query("eat_func") ) return 1;

	set("value", 0);
	add("food_remaining", -1);
	if( !query("food_remaining") ) {
		string msg = query("eat_msg");
		if (msg) {
		  	message_vision(msg, this_player(), this_object());
			message_vision(name() + "�����ˡ�\n", this_player());
		} else
			message_vision("$N��ʣ�µ�" + name() + "�Եøɸɾ�����\n", this_player());
		if( !this_object()->finish_eat() )
			destruct(this_object());
	} else 
	{
		string msg = query("eat_msg");
		if (msg)
		  	message_vision(msg, this_player(), this_object());
		else
		  	message_vision("$N����" + name() + "���˼��ڡ�\n", this_player());
	}
	return 1;
}

