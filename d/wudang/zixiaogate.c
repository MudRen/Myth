//Room: zixiaogate.c ����������
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","����������");
      set("long",@LONG
�����ߵ���չ����£�ǰ������䵱ɽ��Ϊ���Ĺ����������ˡ�
������ɽ�������ߵʹ������¡���Χ��ľɭɭ��������֣���ɫ���ġ�
�������䵱ʦͽ����Ҫ�������
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northwest"  : __DIR__"shibapan",
          "southup"    : __DIR__"guangchang",
      ]));
        set("objects", ([
           __DIR__"npc/wulei": 1,
        ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
