inherit ROOM;
void create()
{
  set ("short", "��ҰС·");
  set ("long", @LONG

����С·��֪��ͨ��ʲô�ط�����������ǰ��������һ���׺����ϴ�ү��
��˵��λ�ϴ�ү����ͨ���ģ�����������䷲�²���֪������˵˭Ҫ��
�ܸ���λ�����������һ�棬�����ѵõ������ĸ�����
LONG);
        set("exits", ([
        "north": __DIR__"diaoyu2",
 "south": __DIR__"diaoyu4",
]));
    set("outdoors", __DIR__);
  setup();
}
