inherit __DIR__"yaoguai.c";


void set_skills()
{
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "hebi" :),
        (: perform_action,"unarmed", "tougu" :),
        (: cast_spell, "feng" :),
        (: cast_spell, "mei" :),
        (: exert_function, "recover" :),
        }) );        
}
