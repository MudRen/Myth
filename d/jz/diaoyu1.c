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
        "northup": __DIR__"sgate",
        "south": __DIR__"diaoyu2",
]));
    set("outdoors", __DIR__);
  setup();
}
