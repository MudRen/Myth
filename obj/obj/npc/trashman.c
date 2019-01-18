#include <ansi.h>
inherit NPC;
int clean_trash();
int dest_trash();

void create()
{
        int i,amun;
        string *order = ({"��", "��", "��", "��", "��", "��", "֣", "��", "��",
"��", "��", "��", "��", "��", "��", "κ", "��" });
        string *orderr = ({"�ٽ�", "Ʈ��", "���", "����", "����",
"����", "�ư�", "����"});
        set_name( order[random(17)] + orderr[random(8)], ({ "shou", "chang" }) );
        set("title", "��������");
        set("gender", "����" );
        set("age", random(20)+20);
        set("env/wimpy",90);
        set("vendetta_mark", "authority");
        set("str", 30);
        set("long","������Ϊ�˱��ֻ�������࣬�ص�Ƹ����\n
�����޼ҿɹ�������������\n");
        set("chat_chance", 80);
        set("chat_msg", ({
                (: clean_trash :),
                (: dest_trash :)
        }) );

        set("attitude", "friendly");
        set("combat_exp", 1000);
        setup();
}

void init()
{
// clean up all trash
        object room;
        int i;
        object *inv;
        dest_trash();

        room = environment(this_object());

        if(room){
                inv = all_inventory(room);
                for(i=0; i<sizeof(inv); i++) {
                        if( userp( inv[i]) ){
                                if ( !random(5))
                                        set_leader(inv[i]);
                                        continue;
                        }
                        if( inv[i]->query("no_shown")) continue;
                        if( inv[i]->query("no_get")) continue;
                        if( inv[i]->is_character()) continue;
                        if( inv[i]->is_corpse()) continue;
                        command("get "+ inv[i]->query("id"));
                }
        }
}

int randommove()
{
        mapping exits;
        string *dirs;
        string thisdir;
        if( !mapp(exits = environment()->query("exits")) ){
                destruct(this_object());
                return 0;
        }
        dirs = keys(exits);
        thisdir = dirs[random(sizeof(dirs))];
        this_object()->set("last_dir",thisdir);
        command("go " + thisdir);
}

int clean_trash()
{
        mapping exits;
        string *dirs;
        string last_dir;
        if( last_dir = this_object()->query("last_dir")){
                if( !mapp(exits = environment()->query("exits")) ){
                        destruct(this_object());
                        return 0;
                }
                dirs = keys(exits);
                if( member_array(last_dir, dirs) != -1){
                        if( random(2) )
                                command("go "+ last_dir);
                        else
                                randommove();
                }
                else
                        randommove();
        }
        else
                randommove();
}

int dest_trash()
{
        object *inv;
        int i,j;
        inv = all_inventory(this_object());
        j = sizeof(inv);
        for(i=0; i<j; i++)
                destruct(inv[i]);
}
