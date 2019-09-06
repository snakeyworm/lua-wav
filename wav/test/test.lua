
local wav = require "wav"
print( wav.play( "C:/Users/clkid/Desktop/SoftwareDev/Python/Projects/NOVA/splat.wav", wav.SND_LOOP | wav.SND_ASYNC ) )

for k, v in pairs( wav ) do
    print( k, v )
end

local start = os.time()

while os.time() - start ~= 3 do end
print( "Done" )
