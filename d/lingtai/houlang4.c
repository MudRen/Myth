// Room: some place in ��ţ����
// houlang4.c

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
                "northeast" : __DIR__"houlang5",
                "southeast" : __DIR__"houlang3",
        ]));

        setup();
}

