//Cracked by Roath
#include <ansi.h>
#define LAST_PAR "bc"
#define THIS_PAR "bcsf"
inherit ITEM;
void create()
{
    set_name(HIW"�����β���̨"NOR, ({ "table"}));
    set_weight(5000000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("no_get","���̨���Ǵ����θ���ҷ�����ģ��㲻��͵��");
        set("long","һ���޴��ޱȵ�����̨����������˷�����ҵ��������ûȥ����ҿ�������(pick gift)����");
        set("value", 0);
        set("material", "stone");
    }
}
void init()
{
    add_action("do_pick", "pick");
}
 
int do_pick(string arg)
{
       object me,obj;
       me = this_player();
       if( !arg || arg!="gift" ) return notify_fail("��Ҫ��ʲô��\n");

 //      return notify_fail("����û�������á�\n");

       if (me->query(THIS_PAR + "_pick")) {
       tell_object(me,CYN "���С�ǵ���ӰͻȻ������һ������֮�С�\n\n");
       tell_object(me,HIR "���С��һ�������������ϣ�С���ѣ���Ҫ̫̰��Ŷ��ÿ��ֻ��һ�����\n\n");
       tell_object(me,CYN "ֻ��һ��������ᣬ���С�ǵ���Ӱ�Ѿ������ˡ�\n" NOR);
       return 1;
       }
      obj = new (__DIR__"gift");
      obj->move(me);
       message_vision("$N������̨������һ���������\n",me );
//ÿ�μ���������ϴεĲ������������ӱ����õĲ����� 
       me->delete(LAST_PAR + "_pick");
       me->set(THIS_PAR + "_pick",1);
       return 1;
}

