inherit NPC;
string *first_name =
({"��","��","��","��","��","��","��","��","��","��","��","��","��","��","ľ","ˮ","��","��"});
string *name_words =({"��","��","��","��","��", "��","��", 
"¹","��","��","�","��","��","��","Գ","��","��","ţ", "�","��","��","��"});

string *last_words=({"��"}); 
void create()
{
         string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
	name += last_words[random(sizeof(last_words))];
        set_name(name, ({ "ghost"}) );
        set("gender", "����" );
        set("age",40);
        set("str", 30);
        set("int", 20);
        set("con", 30);
        set("spi", 20);
        set("per", 15);
        set("class", "ghost");
        set("attitude", "heroism");
        set("combat_exp", 200000+random(30000));
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("force",800);
        set("max_force",800);
        set("force_factor", 90);
        set("mana", 800);
        set("max_mana", 800);
        set("mana_factor", 40);
        set_skill("unarmed",120);
        set_skill("dodge",120);
        set_skill("parry",120);
	set_skill("jinghun-zhang", 120);
	map_skill("unarmed", "jinghun-zhang"); 

	set("HellZhen", 3);
        setup();
        carry_object("/d/obj/armor/shoupi")->wear();
}

void invocation(object who)
{
	object me=this_object();
	COMBAT_D->do_attack(me, who, query_temp("weapon"));
	destruct(me);
}
