//Room: shibapan.c ʮ����
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","ʮ����");
      set("long",@LONG
����һ���ܴ��б�£��׳�ʮ���̣���ʯ��һ��һ����ֱ���ϣ��ķѽ�����
�����������񣬹չ�����������ʮ��֮������������
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northeast"  : __DIR__"taizipo",
          "southeast"  : __DIR__"zixiaogate",
      ]));
      set("objects", ([
                __DIR__"npc/wulei": 1,
      		__DIR__"npc/snake": 1,
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
