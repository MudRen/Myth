// �����-book by Calvin
// skyriver-rake

inherit ITEM;

void create()
{
        set_name("������ٷ���", ({"rake-book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
        set("material", "paper");
        set("skill", ([
                        "name": "skyriver-rake",
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 100,
]) );
        }
}
