#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short", "��������");
 set("long", @LONG
�����ܲ��ľ����������̣�����ͨ��������ķ��򡣵Ͱ���
С���Ե�ס���ߣ�ʹ�˱治�巽�򡣵��²������õĿ�Ҷ��������
��ġ�ż����һ�������ݴӵ��ϵĻ�ˮ��ӿ��������������Ż�Ĵ�
����ζ��
LONG
 );
 set("exits", ([
  "west" : __DIR__"zhaoze1",
]));
        set("item_desc", ([
          "bush": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n",
          "����": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n"
        ]) );
 set("coor/x",20);
 set("coor/y",-620);
 set("coor/z",-20);
 setup();
}
void init()
{ object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(10) + 1, ob);
 add_action("do_chop","chop");
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
 {
tell_object(this_object(), HIR "\n\n���µ�����ͻȻ�ѿ���һ�ų��ȵĵػ�����Ȫ���������\n\n" NOR);
damage = random(20)+10 - ob->query_temp("apply/armor_vs_spells");
 if(damage > 0 ) {
        ob->receive_wound("kee", damage);
 COMBAT_D->report_status(ob,1);
 }
 if( environment(ob) == this_object())
 call_out("blowing",random(10)+1, ob);
 }
 else
 return 1;
}
void reset()
{
 ::reset();
        remove_call_out("blowing");
        delete("exits/south");
}
int valid_leave(object me, string dir)
{
        remove_call_out("blowing");
 return 1;
}
int do_chop(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ����ʲô��\n");
                return 1;
        }
        if( arg == "bush" || arg == "����" )
        {
        me = this_player();
        obj = me->query_temp("weapon");
        if( !obj )
        {
        write("������֣���ô����\n");
        return 1;
        }
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"zhaoze3");
message_vision(sprintf("$N�����е�%s����һ�����ϵ�·��\n",obj->name()),me);
 me->start_busy(1);
        }
        else
message_vision(sprintf("$N�����е�%s����·�ߵľ�����\n",obj->name()),me);
        }
        else
         write("��Ҫ����ʲô��\n");
                return 1;
}
