#include <weapon.h>

inherit THROWING; 
void create()
{
        set_name("������", ({ "wuyang zhen" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                 set("material", "iron");
                set("long", "��ɽ��ʼ��л�����ȡ��ɽ���ֺ��������ƶ��ɵİ�����\n");}
                setup();
}
