// ������ by Calvin

#include <room.h>
inherit ROOM;

int block_cmd(string);
void create ()
{
  set ("short", "����¥");
  set ("long", @LONG

�����ǽ�������������������¥,����������￪���Լ��İ��ɣ������Լ����ֵ�
�ڽ����ϺúõĴ���һ��������Ҫ�����Լ��İ��ɿɲ��Ǻ����׵�,�����������
�����ú����и����⣬������Ҫ����ʮ�����ƽ����˳���Ŀ��������

LONG);

     set("exits", ([ /* sizeof() == 2 */
    "down" : "/d/calvin/lanling/xingyuejiulou",
    "east" : "/d/calvin/lanling/clubroom",
]));

        set("objects", 
        ([ //sizeof() == 1
          "/d/calvin/npc/cluber" : 1,
        ]));

  setup();
        call_other("/obj/board/bangpai_b", "???"); 
}

void init()
{
    add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "xiudao") return 1;
    if (verb == "exert") return 1;
    return 0;
}
int valid_leave(object me, string dir)
{
        object mbox,*inv;
        inv = all_inventory(me);
        if ( !me->query_temp("rent_paid") && dir == "east" )
        return notify_fail("����ʹ��������Ц�ص�ס���㣺�Բ��𣬺����ǰ��������ң�����������ɵ��ˣ�������š�\n");
        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, " \n");
                destruct(mbox);
        }
        return ::valid_leave(me, dir);
}

