// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��ϼ��");
  set ("long", @LONG

��ϼ���ǳǱ�һ��������Ĵ������������ഫ�����Ϲ�������
���γǱ�ҹ��ϼ���������Ȼ��ʥ���ﻳ̥����̫�ӣ��ʽ��˽���
��Ϊ��ϼ����ʾ���顣�����Ƿ������ֵĽֿڡ�

LONG);

  set("exits", ([ 
    "west" : __DIR__"beixia2",
    "east" : __DIR__"jiekou",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
