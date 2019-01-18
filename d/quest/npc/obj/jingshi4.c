# include <skill.h>
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"�ƾ�ʯ"NOR, ({"huangjing shi", "huangjing", "shi"}));
	set_weight(1);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
		set("value",0);
		set("unit","��");
		set("long","�߲�ˮ��֮һ��\n");
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
	add_action("do_combine","combine");
}
void destruct_me(object where, object me)
{
	object pearl;
        if( pearl=new("/d/npc/obj/jingshi"))
        	pearl->move(where);
	message_vision("$N���е�$nͻը�ѿ�����һ��ϼ������ʧȥ����ɫ��\n",where,me);
	destruct(me);
}
int do_combine()
{
	object me,a,b,c,d,e,f,g,real;
	me=this_player();
	a=this_object();

	if( (int)me->query("force") < 2000)
		return notify_fail("����������㣬���ѷ����߲�ˮ����������\n");
	if( (int)me->query("mana") < 2000)
		return notify_fail("��ķ������㣬���ܶ�Ϥ�߲�ˮ���Ķ���\n");

	 if ( !(c=present("zijing shi",me)))
                return notify_fail("�㽫����ˮ��ʯ��Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
        if ( !(d=present("hongjing shi",me)))
                return notify_fail("�㽫����ˮ��ʯ��Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
        if ( !(e=present("chengjing shi",me)))
                return notify_fail("�㽫����ˮ��ʯ��Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
        if ( !(f=present("lanjing shi",me)))
                return notify_fail("�㽫����ˮ��ʯ��Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
        if ( !(g=present("lvjing shi",me)))
                return notify_fail("�㽫����ˮ��ʯ��Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
        if ( !(b=present("baijing shi",me)))
                return notify_fail("�㽫����ˮ��ʯ��Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");

	if( real=new("/d/npc/obj/jingshireal")){
		destruct(b);
                destruct(c);
                destruct(d);
                destruct(e);
                destruct(f);
                destruct(g);
	real->move(me);
	message_vision("$N������ˮ��ʯ�����֮��ںã�ֻ������ϼ���ӹ���7��ˮ��ʯ��Ȼ��Ϊһ�塣\n",me);
	destruct(a);
	}
	return 1;
}


