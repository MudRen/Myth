#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"������"NOR, ({ "jobzhu1" }) );
    set_weight(1);
    set("no_put", 1);
    set("value", 0);
    if( clonep() )
    set_default_object(__FILE__);
    else {
               
            set("no_put", 1);
            set("no_steal", 1);
            set("no_get", 1);
            set("no_beg", 1);
            set("value", 0);
            set("unit", "��");
            set("material", "paper");
            set("long", "��������֮һ,�������ҵ������������(hebing)��\n");
          }

    setup();
}

void init()
{
    add_action("do_eat", "eat");
    add_action("do_hebing","hebing");
}

int do_hebing()
{
        object me,ob;
        me = this_player();
    if (!(ob = present("jobzhu2", me)) 
    || !(ob = present("jobzhu3", me))
    || !(ob = present("jobzhu4", me))
    || !(ob = present("jobzhu5", me))
    || !(ob = present("jobzhu6", me))
    )
        tell_object(me,"�������û�д��롣\n");
  else{
        if( ob->query("ownmake"))
        return notify_fail("�������ƺ��мٻ��ɡ�\n");
        if(userp(ob))
        return notify_fail("�������ƺ��мٻ��ɡ�\n");
        if( ob->is_character() || ob->is_corpse() )
        return notify_fail("�������ƺ��мٻ��ɡ�\n");
        message_vision(MAG"$N�Ѵӻ����ó��ı�ļ�������,�����е�������ϳ���һ���޵��鲢������ȥ��\n", me);
        me->add("combat_exp", 10000);
        me->add("daoxing",10000);
        me->add("potential",1000);        
        
        destruct(present("jobzhu2",me));
        destruct(present("jobzhu3",me));
        destruct(present("jobzhu4",me));
        destruct(present("jobzhu5",me));
        destruct(present("jobzhu6",me));
        destruct(this_object());}
        return 1;
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

        me->add("combat_exp", 800);
        me->add("daoxing",800);
        me->add("potential",150);        
        
        message_vision(HIG "$N�������������ȥ��ֻ����ȫ������˲��٣�\n" NOR, me);
        
        destruct(this_object());
        return 1;
}

