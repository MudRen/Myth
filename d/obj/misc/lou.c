inherit ITEM;

void create()
{
        set_name("��˿¨", ({ "qingsi lou","lou" }) );
        set_weight(1000);
        set_max_encumbrance(180000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "�ഫ������˽�����װʳ���ר��������,�ⶫ����������ľ���,��˵����װ����!\n");
                set("value", 5000);
        }
}
int is_container() { return 1; }
