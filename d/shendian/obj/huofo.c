inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("���", ({"huofo", "fo"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ������������ƵĹŷ�");
                set("base_unit", "��");
                set("base_weight", 0);
                set("no_sell","��ô���Ķ�������ɲ����գ�" );
             set("no_give","��ô���Ķ��������˲���ð�"); 
        }
        setup();
}
void init()
{
    add_action("do_jie", "lianzhi");
}

int do_jie()
{
     object me,ob, obj, obj1, obj2, obj3, obj4, pan;
     me = this_player();
     ob = this_object();
     obj = present("mufo", me);
     obj1 = present("jinfo", me);
     obj2 = present("bingfo", me);
     obj3 = present("shifo", me);
     if(!objectp(obj))
           return notify_fail("������û��ľ�����ҵ�ľ����˵�ɡ�\n");
     if(!objectp(obj1)) 
           return notify_fail("������û�н�����ҵ������˵�ɡ�\n"); 
     if(!objectp(obj2)) 
           return notify_fail("������û�б������ҵ�������˵�ɡ�\n");
     if(!objectp(obj1)) 
           return notify_fail("������û��ʯ�����ҵ�ʯ����˵�ɡ�\n");
  message_vision(HIY"\nֻ������һ����$N���е����������һ��ϼ���к�Ϊһ�壬 �����һ��������ͣ���\n"NOR, me);
     pan = new("/d/shendian/obj/niepan")->move(me, 1); 
     destruct(obj);
     destruct(obj1);
     destruct(obj2);
     destruct(obj3);
     destruct(ob);
     destruct(ob);
     return 1;
}

