//created by daiyu
//2000-12-9 23:35

inherit __DIR__"yaoguai.c";


void set_skills()
{
	set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "fumo" :),
        (: perform_action,"unarmed", "sword" :),
        (: cast_spell, "fu" :),
        (: cast_spell, "shou" :),
        (: exert_function, "recover" :),
        (: exert_function, "zhanqi" :),
        }) );        
}
