inherit ROOM;
void create()
{
  set ("short", "С�ӱ�");
  set ("long", @LONG

���ߵ�����о����������������磬������ֵ��ǣ������Ѿ��Ǻ���
���£�������ô��������������ƬƬ������ɫ�ĺ��̡�һ��С������
�����ǰ����ϸ��֮��ʱ��ʱ�Ļ��ܿ��������ˮ��Ϸ�Ρ���Զ��
һλ����İ׺����ϴ�ү�����ﴹ�������㾪��������е���˵�ǰ
�˵����������Ȼû���㹳�������ľ���ס���ʵ���ʲô...

LONG);
        set("exits", ([
        "north": __DIR__"diaoyu3",
//        "south": __DIR__"diaoyu2",
]));
  set("objects", ([ /* sizeof() == 1 */
// 19    "/d/quest/dajiu/jiangziya" : 1,
  "/d/quest/dajiu/jiang" : 1,
]));
        set("no_fight", 1);
    set("outdoors", __DIR__);
  setup();
}
