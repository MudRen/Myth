// �����ٷ�-book by Calvin
// rake.

inherit ITEM;

void create()
{
        set_name("���ٷ����š�", ({"book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
        set("material", "paper");
        set("skill", ([
                        "name": "rake",
                        "sen_cost": 30,
                        "difficulty": 20,
                        "max_skill": 20,
]) );
        }
}
