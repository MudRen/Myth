// created by kuku@sjsh 2002/12
#include <ansi.h>
inherit ROOM;
int block_cmd(string);

void create ()
{
    set ("short", HIG"�ƹ�"NOR);
    set ("long", @LONG

��������ľ���ζ���������Ʈʮ����°���֮���޲�Ϊ�ܵ�
���ƹ������ľƶ��Ժ�����������þƣ�����ȴ��֮���ס������
�Ǿ��������ľƹȡ�
LONG);

    set("exits", ([ 
        "up"    : "/d/meishan/longwan",
      ]));
    set("objects", ([ 
        __DIR__"npc/jiugui" : 1,
      ]));
  set("no_fight", 1);
  set("no_magic", 1);
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
    if (verb == "bian") return 1; 
    if (verb == "cast") return 1; 
    if (verb == "ji") return 1; 
    if (verb == "perform") return 1; 
    return 0;
}
