// ���� by Calvin

# include <skill.h>
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR "������" NOR, ({ "hong longzhu","zhu" }));
        set_weight(1);
        if( clonep() )
        set("long", "����һ��Ư����Сʯͷ��,�������|��������|,��˵�����ռ������߿��������һ��ʱ����� ...\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_sell",1);
                set("value",0);
                set("unit","��");
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
                return notify_fail("����������㣬���ѷ��������������\n");
        if( (int)me->query("mana") < 2000)
                return notify_fail("��ķ������㣬���ܶ�Ϥ����Ķ���\n");

         if ( !(b=present("liang longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
         if ( !(b=present("fen longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
         if ( !(b=present("lan longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
         if ( !(b=present("huang longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
         if ( !(b=present("qing longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");
         if ( !(b=present("bai longzhu",me)))
                return notify_fail("�㽫���������Ū�˼��£�ȴһ�����񣬴�Ż�û���ռ�����\n");

        if( real=new("/d/longzhu/npc/long")){
                destruct(b);
                destruct(c);
                destruct(d);
                destruct(e);
                destruct(f);
                destruct(g);
        real->move(me);
message_vision(                   
             HIY"$N������"HIG"����"HIY"�����֮��ںá�           

             "HIB"ֻ���߿�"HIG"����"HIB"��â����,��֮������һֻ˶���ޱȵ�"HIW"����"HIB"��

                          "HIR"������"HIW"Ҳ��������������"HIG"����"HIW"���Է����ˡ�\n"NOR,me);
        destruct(a);
        }
        return 1;
}



