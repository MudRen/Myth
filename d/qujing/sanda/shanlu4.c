//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.14

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

ǧ��żʣ��������٣��������ʷ��ˮ���������������괹�ң�
ʯ���������ף�Գ������ݾ���ϣ��������ϲ��ա�����������
���꣬һ����Ũû���ޡ�

LONG);

  set("exits", ([
        "eastdown"     : __DIR__"shanlu3",
        "west"     : __DIR__"shanlu5",
      ]));
  set("objects", ([
        __DIR__"npc/nuzi":1,
        ]));
  set("outdoors",1);
  setup();
}
int valid_leave(object me, string dir)
{
   if (dir == "west" ) {
        if (objectp(present("nu zi", environment(me))))
        return notify_fail("Ů�Ӷ���Ц������һ�����˰ɣ����Ե㶫���ɡ�\n");
        }
        return ::valid_leave(me, dir);
}
