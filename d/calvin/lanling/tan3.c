inherit ROOM;
#include <ansi.h>

int block_cmd(string);
void create ()
{
  set ("short","��Ԩ��ˮ̶");
  set ("long", @LONG

���������Ԩ��ˮ̶��,����Կ�����ð�Ű�����̶ˮ����ô�Ľྻ,
�������������������ˮ�����е����⸴�湦�ܵĹ�Ч�ˡ�
LONG);

  set("exits", ([ /* sizeof() == 4 */
    "east": "/d/calvin/lanling/tan",
    "southwest": "/d/calvin/lanling/tan2",
]));

  set("chat_room",1);
  set("objects", ([ /* sizeof() == 2 */
    "/obj/boss/lanling_jinshui" : 1,
  ]));

  set("no_time",1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("freeze",1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  set("valid_startroom", 1);
  setup();
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
        return notify_fail("˰��������Ц�ص�ס���㣺�Բ����Ǳ��Ǿ�ˮ̶����������Ŀ��ˣ�������š�\n");
        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "�㽫���佻�ظ��ʲ\n");
                destruct(mbox);
        }

        return ::valid_leave(me, dir);
}
