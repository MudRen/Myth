// Room: /u/hkgroup/path1

#include <room.h>
inherit ROOM;

void init();
void do_close2();
int do_push(string);
int valid_leave();
string look_door2();

void create ()
{
  set ("short", "����ͨ��");
  set ("long", @LONG

����ӭ��һ�����ֵ�����ǰ������΢¶��С����
ɽ���о����ʯһ��(stone)��

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "door" : (: look_door2 :),
  "stone" : "
��������������ͨ�ġ�

",
]));
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"pavilion",
  "out" : __DIR__"bula",
  "east" : __DIR__"cglaem",
  "west" : __DIR__"dream",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}

void init()
{
        add_action("do_push", "push");
        add_action("do_close", "close");
}

void close_door2()
{
        object room;

        if(( room = find_object(__DIR__"workroom")) ) {
                delete("exits/out");
                        message("vision", "��֨һ��, ���������غ����ˡ�\n",
                        this_object());
                room->delete("exits/enter");
                message("vision", "��֨һ��, ���Ŵ����������غ����ˡ�\n", room);
        }
        else message("vision","ERROR: door not found(close).\n", room);

}

int do_close(string arg)
{
        object room;

        if (!query("exits/out"))
                return notify_fail("�����Ѿ��ǹ��ŵ��ˡ�\n");

        if (!arg || (arg != "door" && arg != "out"))
                return notify_fail("��Ҫ��ʲô��\n");

        remove_call_out("close_door2");
        call_out("close_door2", 2);

        return 1;
}

int do_push(string arg)
{
        object room;

        if (query("exits/enter"))
                return notify_fail("�����Ѿ��ǿ����ˡ�\n");

        if (!arg || arg!="door")
                return notify_fail("��Ҫ��ʲô��\n");

        if( room = find_object(__DIR__"workroom") ) {
                set("exits/out", __DIR__"workroom");
                message_vision("$N������������ţ�ֻ��֨��һ�������������ؿ���һ���졣\n",
                        this_player());
                room->set("exits/enter", __FILE__);
                message("vision", "\n�����������ţ�ֻ��֨��һ�������������ؿ���һ���졣\n", 
                        room);
                remove_call_out("close_door2");
                call_out("close_door2", 10);

        }
        else message("vision", "ERROR: door not found(push).\n",this_player());

        return 1;
}

int valid_leave(object me, string dir)
{
        if (dir != "exits/out") {
                return ::valid_leave(me,dir);
        }

        if (!::valid_leave(me,dir)) return 0;
}

string look_door2()
{
        return("һ�����˳���Ľ��š�\n�������������š�\n");
}
