// Room: some place in ��ţ����
// houlang1.c

inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG

��ֻ��һǽ֮����ǰ�õ�����ȴһ��Ҳ�������ˡ����Ҷ�����
�֣�΢�紵�������з����������������ȱߵ�ľ���Ե��൱��
�ɣ�ȴһ����Ⱦ��Ҳ������ʱ����ɨ������������ľ��ͨ����
�����
LONG);

        set("exits", ([ /* sizeof() == 2 */
                "northwest" : __DIR__"houlang2",
                "south" : __DIR__"jingtang",
        ]));

        setup();
}

