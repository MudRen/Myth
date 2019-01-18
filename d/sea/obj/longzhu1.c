# include <skill.h>

inherit ITEM;

void create()
{
        set_name("������", ({"jin longzhu", "zhu", "pearl"}));
	set_weight(100);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
		set("value",0);
		set("unit","��");
		set("long",
"һ�Ŷ���Բ������飬��˵ֻ�еõ��������Ż��С�
���й�Ӱ�ζ����ƺ�����(touch)֮�»ᷢ����ʡ�
��������ƺ����а˹�֮�࣬Ҳ���ܺϲ�(combine)���������顣\n");
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
	add_action("do_combine","combine");
}
void destruct_me(object where, object me)
{
	object pearl;
        if( pearl=new("/d/sea/obj/pearl"))
        	pearl->move(where);
	message_vision("$N���е�$nͻ���߲�֮�⣬һ��ϼ������ʧȥ����ɫ��\n",where,me);
	destruct(me);
}
int do_combine()
{
	object me,a,b,c,d,e,f,g,h,i,real;
	me=this_player();
	a=this_object();

	if( (int)me->query("force") < 1500)
		return notify_fail("����������㣬���ѽ�����ϲ���\n");
	if( (int)me->query("mana") < 1000)
		return notify_fail("��ķ������㣬����֧������Ķ���\n");

	if ( !(b=present("yin longzhu",me))) 
		return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
        if ( !(c=present("chi longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
        if ( !(d=present("cheng longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
        if ( !(e=present("huang longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
        if ( !(f=present("lu longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
        if ( !(g=present("qing longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
        if ( !(h=present("lan longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
        if ( !(i=present("zi longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");

	if( real=new("/d/sea/obj/longzhureal")){
		destruct(b);
                destruct(c);
                destruct(d);
                destruct(e);
                destruct(f);
                destruct(g);
                destruct(h);
                destruct(i);
	real->move(me);
	message_vision("$N���������鰴�˹�֮λ���ڽ�������Χ��ֻ������ϼ���ӹ����ſ������Ȼ��Ϊһ�塣\n",me);
	destruct(a);
	}
	return 1;
}


int do_study(string arg)
{
	object me,pearl;

	me=this_player();

	if( !arg || (arg!="jin longzhu"
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
