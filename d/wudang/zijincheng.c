//Room: zijincheng.c �Ͻ��ǽ
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","�Ͻ��ǽ");
      set("long",@LONG
�����ػ������Ͻ��ǽ���ܳ������ǽ�ɻ���ʯ��ɽ�����ɣ�������
���ž����پ��ڣ�����Ϊ����·�ڣ�����׳�ۡ�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"     : __DIR__"jinding",
          "south"     : __DIR__"taihedian",
      ]));
      set("outdoors", "wudang");
      set("objects", ([
		__DIR__"npc/wulei": 1,
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
