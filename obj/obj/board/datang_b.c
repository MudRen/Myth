
inherit BULLETIN_BOARD;
#include <ansi.h> 

void create()
{
        set_name(HIY"�λ��Ƴ�"NOR, ({ "board" }) );
        set("location", "/d/wizz/passion/datang1");
        set("board_id", "datang_b");
       set("long", HIM"\n���ٴλ�ǣ����..........\n"
"���ٴ�˼�����..........\n"
"���ٴ��λ��Ƴ�...........\n"
"�����ŷ���...............\n"
"�ֻ�����ԭ��ֻ������...............\n"
"һ����Ϸһ����........\n"
"����������˯........\n"
"�������￪ʼ........\n"
"��һ��������......��......\n"
NOR
);
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}
