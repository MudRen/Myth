//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
        set_name(HIM"��Ʊ"NOR, ({"dang piao","piao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "���Ƕ��ǵ��̵�ר��Ʊ�ݡ�\n");
                set("unit", "��");
               set("owner_name","������");
               set("owner_id","dong pusheng");
        }
}

