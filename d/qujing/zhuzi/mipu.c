// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

�������̨�ܸߣ��������һ��һ���Ĵ��ס����������һ����ľ
�ܣ�������һ�����߲˺�һЩװ��ʳ�ν��ϡ���̨������������
�ϰ壬����һ˫�����������ۡ�

LONG);

  set("exits", ([ 
    "north" : __DIR__"xi3",
  ]));
  set("objects", ([
"/obj/boss/zhuzi_mi" : 1,
  ]));
  setup();
}
