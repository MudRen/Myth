// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "ի��");
  set ("long", @LONG

����ԭΪӭ��ջ�����ң����ջ���˽���ʩ�����꣬�ѽ�����
�Ҹ�Ϊ��Զ�������Ŀ���������Ϣ�ĵط�����������һľ����
һľ����
    
LONG);

  set("exits", ([
        "south"    : __DIR__"zhaizhan",
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  set("objects", ([
        __DIR__"obj/xifan"    : 1,
        __DIR__"obj/xiaocai"    : 1,
      ]));
  setup();
}

