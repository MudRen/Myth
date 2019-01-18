# include <skill.h>

inherit ITEM;

void create()
{
        set_name("������", ({"lu longzhu", "longzhu", "pearl"}));
	set_weight(100);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
		set("value",0);
		set("unit","��");
		set("long",
"һ�Ŷ���Բ������飬��˵ֻ�еõ��������Ż��С�
���й�Ӱ�ζ����ƺ�����(touch)֮�»ᷢ����ʡ�\n");
	}
	setup();
}
void init()
{

  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
	add_action("do_study","touch");
}
void destruct_me(object where, object me)
{
	object pearl;
        if( pearl=new("/d/sea/obj/pearl"))
        	pearl->move(where);
	message_vision("$N���е�$nͻ���߲�֮�⣬һ��ϼ������ʧȥ����ɫ��\n",where,me);
	destruct(me);
}

int do_study(string arg)
{
	object me,pearl;

	me=this_player();

	if( !arg || (arg!="lu longzhu"
			&& arg!="longzhu"
			&& arg!="pearl") )
		return notify_fail("��Ҫ��ʲô��\n");

	if( (int)me->query_skill("force",1) < 100)
		return notify_fail("����ڹ��ķ������������ܲ��������ڵ�ħ����\n");
	if( (int)me->query_skill("force",1) >= 150)
		return notify_fail("����ڹ��ķ����ߣ������ڵ�ħ���Զ�����������ˡ�\n");
	if( (int)me->query_skill("spells",1) < 50)
		return notify_fail("��ķ������������������򲻵������ڵ�ħ����\n");
	if( (int)me->query("kee") < 50)
		return notify_fail("�����Ѫ���㣬�������ε���ȥ��\n");
	if( (int)me->query("sen") < 50)
		return notify_fail("��ľ��񲻼ã���������Թ�ȥ��\n");
	if( (int)me->query("force") <50)
		return notify_fail("����������㣬�����к����档\n");

	if( (int)this_object()->query("learned") >= (int)me->query("spi")) {
		message_vision("$N���е�$nͻ���߲�֮�⣬һ��ϼ������ʧȥ����ɫ��\n",me,this_object());
		if( pearl=new("/d/sea/obj/pearl")){
			pearl->move(me);
		}
		destruct(this_object());
		return 1;
	}

	message_vision("$N˫������$n��ֻ��һ˿����ϼ���������С�\n",me,this_object());
	me->improve_skill("force", random((int)me->query_int()/2 + (int)me->query_spi()/2)+1+random(3));
	me->receive_damage("kee",30);
	me->receive_damage("sen",30);
	me->add("force",-10);
	this_object()->add("learned",1+random(2));
	write("����ڹ��ķ��������ƺ�������һ�㡣\n");
	return 1;
}
