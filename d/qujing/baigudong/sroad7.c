// Room: come to shanshipo.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "ɽʯ·");
  set ("long", @LONG

    ���ɽ·����Ҫ�߹�ȥ�ˣ��������˳���һ������
    ·�Կɼ�һ��é�ݣ����������������֪�������ڲ�
�ڣ��ڿʵ���������ȥ��һ��ˮ�ȡ�
��
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"shanshipo",
  "eastdown" :__DIR__"sroad6",
  "west" :__DIR__"maowu",
]));

  setup();
}






