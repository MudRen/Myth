// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
ʮ����ФҲ����Ϊʮ�����ޡ����й�����������ʮ��ֻ��������������ֵ��

�������򺥹���·�ϣ�ֻ��ǰ����Կ������صĺ��������ڷ���ɽ���ϣ�
LONG);


        set("exits", ([
 "westup"    :       __DIR__"baiyang",
            "northdown"  :       __DIR__"toby1",
        ]));

        set("outdoors", "12gong");
        setup();
}
