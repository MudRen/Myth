
#include <ansi.h>

string give_gift();

private mixed *story = ({
        "������ƽ�˾�������������",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}
