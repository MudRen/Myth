
inherit ROOM;
int block_cmd(string);
void create ()
{
  set ("short", "���");
  set ("long", @LONG

����������˸�������ƣ��������ƣ������ǵ����������
��䣬������һ����̨�ף������ǽ�ɫ�ʷﱦ����һ��Ů������
����Ȼ���������߸���һ����Ů��Ȼ��������̬��ׯ��

LONG);

  set("exits", ([
        "south"   : __DIR__"dadian",
      ]));
  set("objects", ([
        __DIR__"npc/shinv" : 2,
        __DIR__"npc/wuzetian" : 1,
     "/d/quest/feizei/feizei":1,
       ]));

  set("no_fight",1);
  set("no_magic",1);
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

